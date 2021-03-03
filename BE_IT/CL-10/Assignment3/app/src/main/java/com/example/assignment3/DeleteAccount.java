package com.example.assignment3;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class DeleteAccount extends AppCompatActivity {

    SessionManager sessionManager;
    DbHelper dbHelper;
    TextView uname;
    EditText pass;
    String text;
    Button submit,back;
    @SuppressLint("SetTextI18n")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_delete_account);

        dbHelper = new DbHelper(this);
        sessionManager = new SessionManager(this);
        uname = findViewById(R.id.DeleteUsername);
        submit = findViewById(R.id.deleteSubmit);
        back = findViewById(R.id.deleteBack);
        pass = findViewById(R.id.deletePass);
        text = sessionManager.getSession();
        uname.setText(text+" Please enter your password to delete your account");

        submit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(dbHelper.deleteAccount(text,pass.getText().toString())){
                    sessionManager.removeSession();
                    startActivity(new Intent(DeleteAccount.this,MainActivity.class));
                    Toast.makeText(getApplicationContext(),"Account deleted Successfully",Toast.LENGTH_LONG).show();
                }
                else{
                    Toast.makeText(getApplicationContext(),"Unable to delete the account, Please check Password",Toast.LENGTH_LONG).show();
                }
            }
        });

        back.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(DeleteAccount.this,WeatherActivity.class));
            }
        });
    }
}