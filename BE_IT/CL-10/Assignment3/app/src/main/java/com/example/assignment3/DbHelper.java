package com.example.assignment3;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

import java.util.ArrayList;

//A helper class to manage database creation and version management.
public class DbHelper extends SQLiteOpenHelper {

    public DbHelper(Context context) {
        //Create a helper object to create, open, and/or manage a database.
        super(context, "user.db", null, 1);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        //create table in db
        db.execSQL("create table authenticate(name TEXT primary key,password TEXT)");
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {

    }

    public boolean insertData(String name, String password) {

        SQLiteDatabase DB = this.getWritableDatabase();

        //ContentValues is a maplike class that matches a value to a String key.

        ContentValues contentValues = new ContentValues();

        //putting name in the key "name"
        contentValues.put("name", name);
        contentValues.put("password", password);

        //insert method inserts the data present in content values into the table
        //first parameter: table name
        //second parameter: the framework doesnt insert values when there are no values
        long result = DB.insert("authenticate", null, contentValues);
        if (result == -1) {
            return false;
        } else
            return true;
    }

    public boolean getData(String username, String password) {
        SQLiteDatabase DB = this.getReadableDatabase();
        Cursor cursor = DB.rawQuery("select * from authenticate where name = ? and password = ?", new String[]{username, password});
        if (cursor.getCount() > 0) {
            return true;
        } else {
            return false;
        }
    }

    public boolean updatePassword(String username, String Password)
    {
        SQLiteDatabase DB = this.getWritableDatabase();
        ContentValues contentValues = new ContentValues();
        contentValues.put("name", username);
        contentValues.put("password", Password);

        Cursor cursor = DB.rawQuery("select * from authenticate where name = ?",new String[]{username});
        if(cursor.getCount()>0)
        {
            long res  = DB.update("authenticate",contentValues,"name = ?",new String[]{username});

            if(res == -1)
                return false;
            return true;
        }else
            return false;
    }

    public boolean deleteAccount(String username,String Password)
    {
        SQLiteDatabase DB = this.getWritableDatabase();

        Cursor cursor = DB.rawQuery("select * from authenticate where name=? and password=?",new String[]{username,Password});
        if(cursor.getCount()>0)
        {
            long res = DB.delete("authenticate","name=?",new String[]{username});
            if(res == -1)
                return false;
            return true;
        }
        else
            return false;
    }

    public ArrayList readAllData()
    {
        String query = "select name from authenticate";
        SQLiteDatabase DB = this.getReadableDatabase();
        ArrayList<String> store = new ArrayList<>();

        Cursor cursor = null;
        if(DB != null)
        {
            cursor = DB.rawQuery(query,null);
            while (cursor.moveToNext()){
                store.add(cursor.getString(0));
            }
        }
        return store;
    }
}
