package com.example.assignment3;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class WeatherActivity extends AppCompatActivity {


    Button b, logout;
    TextView username;
    SessionManager sessionManager;
    String text;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        
        sessionManager = new SessionManager(this);

//        if (!sessionManager.getSession().equals("noUser")) {
//            startActivity(new Intent(WeatherActivity.this, MainActivity.class));
//        }

        username = findViewById(R.id.usernametext);
        if (sessionManager.getSession() != null)
            username.setText(sessionManager.getSession());


        b = findViewById(R.id.backbtn);
        b.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(WeatherActivity.this, MainActivity.class));
            }
        });

    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        switch (item.getItemId()){
            case R.id.changepassword:
                try {
                    startActivity(new Intent(WeatherActivity.this,ChangePassword.class));
                }
                catch (Exception e){
                    Toast.makeText(getApplicationContext(),e.toString(), Toast.LENGTH_LONG).show();
                }
                return true;
            case R.id.deleteAccount:
                try {
                    startActivity(new Intent(WeatherActivity.this,DeleteAccount.class));
                }
                catch (Exception e){
                    Toast.makeText(getApplicationContext(),e.toString(), Toast.LENGTH_LONG).show();
                }
                return true;
            case R.id.logout:
                try {
                    sessionManager.removeSession();
                    startActivity(new Intent(WeatherActivity.this,MainActivity.class));
                }
                catch (Exception e){
                    Toast.makeText(getApplicationContext(),e.toString(), Toast.LENGTH_LONG).show();
                }
                return true;

            default:
                return super.onOptionsItemSelected(item);
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater menuInflater = getMenuInflater();
        menuInflater.inflate(R.menu.weather_menu,menu);
        return true;
    }
}