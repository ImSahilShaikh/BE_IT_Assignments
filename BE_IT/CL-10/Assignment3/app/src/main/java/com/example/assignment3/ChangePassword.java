package com.example.assignment3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class ChangePassword extends AppCompatActivity {

    SessionManager sessionManager;
    EditText pass,confirmpass;
    String username;
    DbHelper dbHelper;
    Button submit,back;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_change_password);

        dbHelper = new DbHelper(this);
        sessionManager = new SessionManager(this);

        pass = findViewById(R.id.p1);
        confirmpass = findViewById(R.id.p2);
        submit = findViewById(R.id.changepassSubmit);
        back = findViewById(R.id.cpback);


        if(sessionManager.getSession() != null)
            username = sessionManager.getSession();


        submit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(pass.getText().toString().equals(confirmpass.getText().toString()))
                {
                    if(dbHelper.updatePassword(username,pass.getText().toString()))
                    {
                        Toast.makeText(getApplicationContext(),"Password Updated",Toast.LENGTH_LONG).show();
                        startActivity(new Intent(ChangePassword.this,WeatherActivity.class));
                    }
                    else
                        Toast.makeText(getApplicationContext(),"Unable to Update Password",Toast.LENGTH_LONG).show();
                }
                else
                    Toast.makeText(getApplicationContext(),"Password and Confirm Password doesnt match",Toast.LENGTH_LONG).show();
            }
        });

        back.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(ChangePassword.this,WeatherActivity.class));
            }
        });
    }
}