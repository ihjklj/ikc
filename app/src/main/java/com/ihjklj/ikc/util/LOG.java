package com.ihjklj.ikc.util;

import android.util.Log;

/**
 * Created by Administrator on 2018/4/4.
 */

public class LOG {

    static public void d(String tag, String data) {
        Log.d(tag, data);
    }

    static public void e(String tag, String data) {
        Log.e(tag, data);
    }
}
