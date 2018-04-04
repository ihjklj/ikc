package com.ihjklj.ikc.service;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import com.ihjklj.ikc.application.MyApplication;
import com.ihjklj.ikc.util.FloatWindowManager;
import com.ihjklj.ikc.util.LOG;

/**
 * Created by Administrator on 2018/3/27.
 */

public class FloatWindowService extends Service {

    private FloatWindowManager mFloatManager;

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override
    public void onCreate() {
        super.onCreate();
        LOG.d(MyApplication.TAG, "service onCreate");
        mFloatManager = new FloatWindowManager(getApplicationContext());
        mFloatManager.createFloatWindow();
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        return super.onStartCommand(intent, flags, startId);
    }

    /**
     * 服务销毁时的回调
     */
    @Override
    public void onDestroy() {
        super.onDestroy();
        LOG.d(MyApplication.TAG, "service destroy.");
        mFloatManager.removeFloatWindow();
    }
}
