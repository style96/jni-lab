package com.android.jnisampleapp;

import android.app.Activity;
import android.os.Bundle;
import android.content.Context;
import android.widget.TextView;
import android.widget.Button;
import android.widget.LinearLayout;
import android.util.Log;
import android.view.View;

public class MainActivity extends Activity {
    private static final String TAG = "JniSampleApp";

    private TextView versionText;

    static {
        System.loadLibrary("JniSampleApp");
    }

    public native String getAndroidVersion();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // Create layout programmatically
        LinearLayout layout = new LinearLayout(this);
        layout.setOrientation(LinearLayout.VERTICAL);

        // version text view
        versionText = new TextView(this);
        layout.addView(versionText);

        // button to call android version using jni
        Button ndkButton = new Button(this);
        ndkButton.setText("Get Android version");
        layout.addView(ndkButton);

        // Set click listener for ndk button
        ndkButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String version = getAndroidVersion();
                versionText.setText("Android version: " + version);
            }
        });

        setContentView(layout);
    }
}
