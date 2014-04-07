#include "../libFireBird.h"

bool ShowPvrList(tPvrListType PvrListType)
{
  TRACEENTER();

  void (*__Appl_PvrList)(unsigned int, unsigned int);
  void (*__Appl_PvrList_SetListType)(tPvrListType ListType);

  if(PvrListType != PLT_Unchanged)
  {
    __Appl_PvrList_SetListType = (void*)FIS_fwAppl_PvrList_SetListType();
    if(!__Appl_PvrList_SetListType)
    {
      TRACEEXIT();
      return FALSE;
    }
    __Appl_PvrList_SetListType(PvrListType - 1);
  }

  __Appl_PvrList = (void*)FIS_fwAppl_PvrList();
  if(!__Appl_PvrList)
  {
    TRACEEXIT();
    return FALSE;
  }

  __Appl_PvrList(0, 0xffff);

  TRACEEXIT();
  return TRUE;
}
