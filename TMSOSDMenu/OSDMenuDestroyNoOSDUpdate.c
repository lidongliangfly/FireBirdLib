#include                "FBLib_TMSOSDMenu.h"

void OSDMenuDestroyNoOSDUpdate(void)
{
  if(OSDRgn)
  {
    TAP_Osd_Delete(OSDRgn);
    OSDRgn = 0;
    if(OSDMenuSelectionBarRgn) TAP_Osd_Delete(OSDMenuSelectionBarRgn);
    OSDMenuSelectionBarRgn = 0;
    OSDMenuLastCursor = LCT_NRCURSORS;
  }
  if(Menu[CurrentMenuLevel].Item) TAP_MemFree(Menu[CurrentMenuLevel].Item);

  CallbackProcedure = NULL;
}
