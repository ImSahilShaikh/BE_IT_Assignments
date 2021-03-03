package com.example.assignment3;

import android.content.Context;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class ShowUsersAdapter extends RecyclerView.Adapter<ShowUsersAdapter.ViewHolder> {

    ArrayList<String> username;
    static int count;

    ShowUsersAdapter(ArrayList<String> username) {
        this.username = username;
    }

    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        Log.i("This is my debug", "onCreateViewHolder" + count++);

        LayoutInflater layoutInflater = LayoutInflater.from(parent.getContext());
        View view = layoutInflater.inflate(R.layout.users_list, parent, false);
        ViewHolder viewHolder = new ViewHolder(view);
        return viewHolder;
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        holder.list_users_txt.setText(username.get(position));
    }

    @Override
    public int getItemCount() {
        return username.size();
    }

    public class ViewHolder extends RecyclerView.ViewHolder {

        TextView list_users_txt;

        public ViewHolder(@NonNull View itemView) {
            super(itemView);
            list_users_txt = itemView.findViewById(R.id.list_users_txt);
        }
    }
}
