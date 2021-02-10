package com.example.assignment2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class Register extends AppCompatActivity {

    Button submitreg,back;
    EditText password, confirmpassword;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);

        submitreg = (Button)findViewById(R.id.submitreg);

        password = (EditText)findViewById(R.id.password);
        confirmpassword = (EditText)findViewById(R.id.confirmpass);

        back = (Button)findViewById(R.id.backtohome);

        back.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(Register.this,MainActivity.class));
            }
        });

        submitreg.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                checkPasswordisEqual(password.getText().toString(),confirmpassword.getText().toString());
            }
        });
    }
    void checkPasswordisEqual(String p1,String p2)
    {
        if(p1.equals(p2))
        {
            Toast.makeText(getApplicationContext(),"Registered",Toast.LENGTH_LONG).show();
            startActivity(new Intent(Register.this,MainActivity.class));
        }
        else
        {
            Toast.makeText(getApplicationContext(),"Password and confirm password are not equal",Toast.LENGTH_LONG).show();
        }
    }
}