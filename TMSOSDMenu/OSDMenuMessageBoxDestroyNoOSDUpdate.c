#include                "FBLib_TMSOSDMenu.h"

void OSDMenuMessageBoxDestroyNoOSDUpdate(void)
{
  TRACEENTER();

  tOSDMapInfo          *OSDMapInfo;

  if(MessageBoxOSDRgn)
  {
    TAP_Osd_Delete(MessageBoxOSDRgn);
    MessageBoxOSDRgn = 0;

    if(InfoBoxSaveArea)
    {
      if(MyOSDRgn)
      {
        OSDMapInfo = (tOSDMapInfo*) FIS_vOsdMap();
        if(OSDMapInfo)
          TAP_Osd_RestoreBox(MyOSDRgn, InfoBoxSaveAreaX - OSDMapInfo[MyOSDRgn].x, InfoBoxSaveAreaY - OSDMapInfo[MyOSDRgn].y, _InfoBox_Gd.width, _InfoBox_Gd.height, InfoBoxSaveArea);
      }
      else if(OSDRgn) TAP_Osd_RestoreBox(OSDRgn, InfoBoxSaveAreaX, InfoBoxSaveAreaY, _InfoBox_Gd.width, _InfoBox_Gd.height, InfoBoxSaveArea);

      TAP_MemFree(InfoBoxSaveArea);
      InfoBoxSaveArea = NULL;
      MyOSDRgn = 0;
    }
  }

  OSDMenuFreeStdFonts();

  TRACEEXIT();
}
