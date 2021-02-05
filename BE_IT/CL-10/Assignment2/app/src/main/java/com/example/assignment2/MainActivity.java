package com.example.assignment2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    EditText username, password;
    Button button;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.login_activity);

        username = (EditText)findViewById(R.id.u);
        password = (EditText)findViewById(R.id.p);
        button = (Button)findViewById(R.id.btn);

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                check_credentials(username.getText().toString(),password.getText().toString());
            }
        });

    }

    void check_credentials(String uname,String pass)
    {
        if((uname.equals("admin")) && (pass.equals("admin")))
        {
            Intent i = new Intent(MainActivity.this,WeatherActivity.class);
            startActivity(i);
        }
        else
        {
            Toast.makeText(getApplicationContext(),"Incorrect Credentials",Toast.LENGTH_LONG).show();
        }

    }
}