package com.example.assignment3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class Register extends AppCompatActivity {

    Button submitreg,back;
    EditText password, confirmpassword, username;
    DbHelper db;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);

        getSupportActionBar().hide();

        username =(EditText)findViewById(R.id.userreg);
        submitreg = (Button)findViewById(R.id.submitreg);

        password = (EditText)findViewById(R.id.passwordreg);
        confirmpassword = (EditText)findViewById(R.id.confirmpass);

        back = (Button)findViewById(R.id.backtohome);

        db = new DbHelper(this);



        back.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(Register.this,MainActivity.class));
            }
        });

        submitreg.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String user = username.getText().toString();
                String pass = password.getText().toString();
                String conpass = confirmpassword.getText().toString();
                Boolean checkInsertData = false;
                if(checkPasswordisEqual(conpass,pass)) {
                    checkInsertData = db.insertData(user, pass);
                }

                if(checkInsertData == true)
                {
                    startActivity(new Intent(Register.this,MainActivity.class));
                }
            }
        });
    }
    boolean checkPasswordisEqual(String p1,String p2)
    {
        if(p1.equals(p2))
        {
            Toast.makeText(getApplicationContext(),"Registered",Toast.LENGTH_LONG).show();
            startActivity(new Intent(Register.this,MainActivity.class));
            return true;
        }
        else
        {
            Toast.makeText(getApplicationContext(),"Password and confirm password are not equal",Toast.LENGTH_LONG).show();
            return false;
        }
    }
}