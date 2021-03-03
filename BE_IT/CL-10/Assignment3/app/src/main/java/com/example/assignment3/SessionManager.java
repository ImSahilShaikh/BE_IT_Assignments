package com.example.assignment3;

import android.content.Context;
import android.content.SharedPreferences;
import android.preference.PreferenceManager;

public class SessionManager {
    SharedPreferences sharedPreferences;
    SharedPreferences.Editor editor;

    String SHARED_PREF_NAME = "session";
    String SESSION_ID = "username";

    SessionManager(Context context) {
        sharedPreferences = context.getSharedPreferences(SHARED_PREF_NAME, Context.MODE_PRIVATE);
        editor = sharedPreferences.edit();
    }

    public void createSession(String username) {
        editor.putString(SESSION_ID, username).commit();
    }

    public String getSession() {
        return sharedPreferences.getString(SESSION_ID, "noUser");
    }

    public void removeSession() {
        editor.putString(SESSION_ID, "noUser").commit();
    }
}
