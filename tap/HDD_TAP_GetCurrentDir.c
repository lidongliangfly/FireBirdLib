#include <string.h>
#include "../libFireBird.h"

//Return codes:     0: OK
//                 -1: not enough memory (from HDD_TAP_GetCurrentDirCluster)
//                 -2: buffer overrun in subdir search (from HDD_TAP_GetCurrentDirCluster)
//                 -3: Lib init failed (from HDD_TranslateDirCluster via HDD_TAP_GetCurrentDirCluster)

int HDD_TAP_GetCurrentDir(char *CurrentDir)
{
  TRACEENTER();

  tTMSTAPTaskTable     *TAPTaskTable;
  dword                *dw;

  //Get all needed variables
  TAPTaskTable = (tTMSTAPTaskTable*)FIS_vTAPTable();

  //The curTapTask variable is not thread safe. Call InitTAPex() if this function will be called from a sub thread
  if(TAP_TableIndex == 0xffffffff)
  {
    dword                *curTapTask;

    curTapTask = (dword*)FIS_vCurTapTask();
    if(!curTapTask)
    {
      TRACEEXIT();
      return -3;
    }
    TAP_TableIndex = *curTapTask;
  }

  if(!TAPTaskTable)
  {
    if(CurrentDir) CurrentDir[0] = '\0';

    TRACEEXIT();
    return -3;
  }

  //CurrentDir points to a struct, where the second dword points to NULL terminated string
  dw = (dword*)TAPTaskTable[TAP_TableIndex].CurrentDir;

  //Remove the systems mount point /mnt/hd from the directory
  if(CurrentDir && dw && dw[1])
    strcpy(CurrentDir, (char*)(dw[1] + 7));

  TRACEEXIT();
  return 0;
}
