package com.ihjklj.ikc.cnative;

/**
 * Created by Administrator on 2018/4/4.
 */

public class IkNativeMethod {

    private static IkNativeMethod mInstance;

    private IkNativeMethod() {}

    public static IkNativeMethod getInstance() {
        if (mInstance == null) {
            synchronized (IkNativeMethod.class) {
                if (mInstance == null) {
                    mInstance = new IkNativeMethod();
                }
            }
        }
        return mInstance;
    }

    static {
        System.loadLibrary("ikc");
    }

    public native int start(int logflag, int killflag);
    public native String getIp(String networkName);
    public native int isProcessExsit(String packageName);
}
