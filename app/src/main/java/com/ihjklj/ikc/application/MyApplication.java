package com.ihjklj.ikc.application;

import android.app.Application;
import com.ihjklj.ikc.util.LOG;

/**
 * Created by Administrator on 2018/4/4.
 */

public class MyApplication extends Application {

    public static final String TAG = "ikc";

    @Override
    public void onCreate() {
        super.onCreate();

        init();
    }

    private void init() {
        LOG.d(TAG, "application init.");
        //
    }
}
