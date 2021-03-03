package com.example.assignment3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    EditText username, password;
    Button button, signup;
    DbHelper db;
    SessionManager sessionManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.login_activity);
        getSupportActionBar().hide();


        sessionManager = new SessionManager(this);

        if (!sessionManager.getSession().equals("noUser")) {
            startActivity(new Intent(MainActivity.this, WeatherActivity.class));
        }


        username = findViewById(R.id.u);
        password = findViewById(R.id.password);
        button = findViewById(R.id.btn);

        signup = findViewById(R.id.signup);

        db = new DbHelper(this);

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                check_credentials(username.getText().toString(), password.getText().toString());
            }
        });

        signup.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(MainActivity.this, Register.class));
            }
        });

    }

    public void check_credentials(String uname, String pass) {
        Boolean check = db.getData(uname, pass);

        if (uname.equals("admin")) {
            Toast.makeText(getApplicationContext(), "Welcome: " + uname, Toast.LENGTH_LONG).show();
            startActivity(new Intent(MainActivity.this, AdminPanel.class));
        }

        if (check == true) {
            Toast.makeText(getApplicationContext(), "Welcome: " + uname, Toast.LENGTH_LONG).show();
            sessionManager.createSession(uname);
            startActivity(new Intent(MainActivity.this, WeatherActivity.class));
        } else {
            if (!uname.equals("admin"))
                Toast.makeText(getApplicationContext(), "User not registered", Toast.LENGTH_LONG).show();
        }
    }
}