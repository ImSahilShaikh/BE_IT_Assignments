package com.example.assignment3;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.database.Cursor;
import android.os.Bundle;

import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;

public class AdminPanel extends AppCompatActivity {

    RecyclerView recyclerView;
    DbHelper db;
    ArrayList<String> users;
    ShowUsersAdapter showUsersAdapter;
    TextView textView;
    Button logout;
    SessionManager sessionManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_admin_panel);

        recyclerView = findViewById(R.id.recylerView);

        logout = findViewById(R.id.adminlogout);

        db = new DbHelper(this);
        users = new ArrayList<>();
        users = db.readAllData();
        showUsersAdapter = new ShowUsersAdapter(users);
        recyclerView.setAdapter(showUsersAdapter);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));

        textView = (TextView) findViewById(R.id.list_users_txt);

        logout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(AdminPanel.this,MainActivity.class));
            }
        });
    }
}