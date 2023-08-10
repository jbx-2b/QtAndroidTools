package com.falsinsoft.qtandroidtools;

import android.content.Context;
import android.app.Activity;
import android.content.Intent;

public class AndroidSettings
{
    private final Activity mActivityInstance;

    public AndroidSettings(Activity activityInstance)
    {
        mActivityInstance = activityInstance;
    }

    public void openTTSSettings()
    {
        Intent intent = new Intent();
        intent.setAction("com.android.settings.TTS_SETTINGS");
        intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        mActivityInstance.startActivity(intent);
    }
}
