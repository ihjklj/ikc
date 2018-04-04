package com.ihjklj.ikc.fragment;
import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ListView;
import com.ihjklj.ikc.R;
import com.ihjklj.ikc.adapter.IkAdapter;
import com.ihjklj.ikc.model.IkListContent;
import java.util.List;

/**
 * Created by Administrator on 2018/4/4.
 */

public class VillageAffairFragment extends Fragment {

    private Context mContext;
    private ListView mListView;
    private IkAdapter mAdapter;
    private List<IkListContent> mContentList;

    @Override
    public void onAttach(Context context) {
        super.onAttach(context);
        mContext = context;
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup group, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.village_affair_layout, group, false);
        initView(view);
        init();
        return view;
    }

    @Override
    public void onDetach() {
        super.onDetach();
    }

    private void initView(View view) {
        mListView = view.findViewById(R.id.village_affair_listview);
    }

    private void init() {
        mContentList = getContent();
        mAdapter = new IkAdapter(mContext, R.layout.content_list_layout, mContentList);
        mListView.setAdapter(mAdapter);
    }

    private List<IkListContent> getContent() {
        return null;
    }
}
