package com.ihjklj.ikc.activity;

import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentTransaction;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.ListView;
import com.ihjklj.ikc.R;
import com.ihjklj.ikc.adapter.IkAdapter;
import com.ihjklj.ikc.fragment.VillageAffairFragment;
import com.ihjklj.ikc.model.IkListContent;
import java.util.List;

/**
 * Created by Administrator on 2018/4/4.
 */

public class FunctionActivity extends AppCompatActivity {

    private Button mVillageAffairButton;
    private Button mNoticeButton;
    private Button mRecevierButton;
    private Button mOwnButton;
    private VillageAffairFragment mVillageAffairFragment;

    @Override
    protected void onCreate(Bundle saveInstanceState) {
        super.onCreate(saveInstanceState);
        setContentView(R.layout.function_layout);

        initView();

        init();
    }

    private void init() {

        mVillageAffairFragment = new VillageAffairFragment();
        setFragment(mVillageAffairFragment);

        mVillageAffairButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //
            }
        });
        mNoticeButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        mRecevierButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        mOwnButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
    }

    private List<IkListContent> getListContent() {
        return null;
    }

    private void initView() {

        mVillageAffairButton = (Button)findViewById(R.id.function_layout_villageAffairs);
        mNoticeButton = (Button)findViewById(R.id.function_layout_notice);
        mRecevierButton = (Button)findViewById(R.id.function_layout_receiver);
        mOwnButton = (Button)findViewById(R.id.function_layout_own);
    }

    private void setFragment(Fragment fragment) {
        FragmentManager fragmentManager = getSupportFragmentManager();
        FragmentTransaction transaction = fragmentManager.beginTransaction();
        transaction.replace(R.id.function_layout_fragment, fragment);
        transaction.commit();
    }
}
