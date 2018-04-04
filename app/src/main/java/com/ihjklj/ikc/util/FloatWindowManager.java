package com.ihjklj.ikc.util;

import android.content.Context;
import android.graphics.PixelFormat;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.WindowManager;
import android.widget.TextView;
import com.ihjklj.ikc.R;
import com.ihjklj.ikc.application.MyApplication;
import com.ihjklj.ikc.cnative.IkNativeMethod;
import com.ihjklj.ikc.ikinterface.NetworkChangeInterface;

/**
 * Created by Administrator on 2018/3/27.
 */

public class FloatWindowManager {

    private Context mContext;
    private WindowManager mWindowManager;
    private View mView;
    private TextView mIpText;
    private IkNativeMethod mNativeMethod;
    private NetworkChangeInterface mInterface;

    public FloatWindowManager(Context pContext) {
        mContext = pContext;

        init();
    }

    private void init() {
        mWindowManager = (WindowManager)mContext.getSystemService(Context.WINDOW_SERVICE);
        //mFloatView = new FloatView(mContext);
        mView = LayoutInflater.from(mContext).inflate(R.layout.float_window_layout, null);
        mIpText = (TextView)mView.findViewById(R.id.float_window_text);
    }

    public void createFloatWindow() {
        LOG.d(MyApplication.TAG, "create float window.");
        final WindowManager.LayoutParams params = new WindowManager.LayoutParams();

        // 类型
        params.type = WindowManager.LayoutParams.TYPE_SYSTEM_ALERT;

        // WindowManager.LayoutParams.TYPE_SYSTEM_ALERT

        // 设置flag

        //int flags = WindowManager.LayoutParams.FLAG_ALT_FOCUSABLE_IM;
        // | WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE;
        // 如果设置了WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE，弹出的View收不到Back键的事件
        params.flags = WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE;
        // 不设置这个弹出框的透明遮罩显示为黑色
        params.format = PixelFormat.TRANSLUCENT;
        // FLAG_NOT_TOUCH_MODAL不阻塞事件传递到后面的窗口
        // 设置 FLAG_NOT_FOCUSABLE 悬浮窗口较小时，后面的应用图标由不可长按变为可长按
        // 不设置这个flag的话，home页的划屏会有问题
        //params.width = LinearLayout.LayoutParams.MATCH_PARENT;
        //params.height = LinearLayout.LayoutParams.MATCH_PARENT;
        params.width = 250;
        params.height = 50;
        params.gravity = Gravity.LEFT | Gravity.TOP;
        mWindowManager.addView(mView, params);
    }

    public void removeFloatWindow() {
        mWindowManager.removeView(mView);
    }
}
