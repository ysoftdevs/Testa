#include "progressbar.h"
#include "nativeprogressbar_mac.mm"

void ProgressBar::show(float progress)
{
    DockDownloadProgressBar* progressBar = [DockDownloadProgressBar sharedDockDownloadProgressBar];
    [progressBar setProgress:progress];
    [progressBar updateProgressBar];
}

void ProgressBar::hide()
{
    DockDownloadProgressBar* progressBar = [DockDownloadProgressBar sharedDockDownloadProgressBar];
    [progressBar hideProgressBar];
}
