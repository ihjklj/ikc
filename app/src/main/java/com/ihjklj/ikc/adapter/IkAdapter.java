package com.ihjklj.ikc.adapter;

import android.content.Context;
import android.text.Layout;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;

import com.ihjklj.ikc.model.IkListContent;

import java.util.List;

/**
 * Created by Administrator on 2018/4/4.
 */

public class IkAdapter extends ArrayAdapter {

    private int mResourceId;

    public IkAdapter(Context context, int resourceid, List<IkListContent> objects) {
        super(context, resourceid, objects);
        mResourceId = resourceid;
    }

    @Override
    public View getView(int position, View v, ViewGroup group) {
        IkListContent content = (IkListContent)getItem(position);
        View view = LayoutInflater.from(getContext()).inflate(mResourceId, null);
        return view;
    }
}
