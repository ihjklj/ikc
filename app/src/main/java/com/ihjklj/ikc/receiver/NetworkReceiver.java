package com.ihjklj.ikc.receiver;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.net.ConnectivityManager;
import android.widget.Toast;
import com.ihjklj.ikc.activity.MainActivity;
import com.ihjklj.ikc.application.MyApplication;
import com.ihjklj.ikc.cnative.IkNativeMethod;
import com.ihjklj.ikc.util.LOG;

/**
 * Created by Administrator on 2018/1/18.
 */

public class NetworkReceiver extends BroadcastReceiver {

    @Override
    public void onReceive(Context context, Intent intent) {
        if (intent.getAction().equals(ConnectivityManager.CONNECTIVITY_ACTION)) {
            LOG.d(MyApplication.TAG, "float window : network changed.");
        }
    }

    private void runProcess(Context context) {
        //Toast.makeText(context, "float window : network changed!", Toast.LENGTH_SHORT).show();
        int res = IkNativeMethod.getInstance().isProcessExsit(context.getPackageName());
        LOG.d(MyApplication.TAG, context.getPackageName() + (res == 1 ? "is running" : "process not exsit"));
        if (res == 0) {
            Toast.makeText(context, "start iktest", Toast.LENGTH_SHORT).show();
            LOG.d(MyApplication.TAG, "package name:" + context.getPackageName());
            LOG.d(MyApplication.TAG, "start MainActivity.");
            Intent startActivityIntent = new Intent(context, MainActivity.class);
            startActivityIntent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
            context.startActivity(startActivityIntent);
        }
    }
}
