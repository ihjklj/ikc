package com.ihjklj.ikc.activity;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;
import com.ihjklj.ikc.R;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main_layout);

        runFunction();
    }

    private void runFunction() {
        Intent intent = new Intent(this, FunctionActivity.class);
        startActivity(intent);
        finish();
    }
}
