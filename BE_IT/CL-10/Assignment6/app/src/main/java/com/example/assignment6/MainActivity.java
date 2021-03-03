package com.example.assignment6;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.view.animation.LinearInterpolator;
import android.view.animation.RotateAnimation;
import android.widget.Button;
import android.widget.ImageView;

public class MainActivity extends AppCompatActivity {

    Animation animation;
    ImageView imageView;
    Button low,mid,high,off;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        imageView = findViewById(R.id.imageView);
        low = findViewById(R.id.low);
        mid = findViewById(R.id.mid);
        high = findViewById(R.id.high);
        off = findViewById(R.id.off);
//
        low.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                RotateAnimation rotateAnimation = new RotateAnimation(0, 360, RotateAnimation.RELATIVE_TO_SELF, .5f, RotateAnimation.RELATIVE_TO_SELF,.5f);
                rotateAnimation.setDuration(3500);

                rotateAnimation.setRepeatCount(Animation.INFINITE);
                rotateAnimation.setInterpolator(new LinearInterpolator());
                imageView.startAnimation(rotateAnimation);
            }
        });

        mid.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                RotateAnimation rotateAnimation = new RotateAnimation(0, 360, RotateAnimation.RELATIVE_TO_SELF, .5f, RotateAnimation.RELATIVE_TO_SELF,.5f);
                rotateAnimation.setDuration(2000);

                rotateAnimation.setRepeatCount(Animation.INFINITE);
                rotateAnimation.setInterpolator(new LinearInterpolator());
                imageView.startAnimation(rotateAnimation);
            }
        });

        high.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                RotateAnimation rotateAnimation = new RotateAnimation(0, 360, RotateAnimation.RELATIVE_TO_SELF, .5f, RotateAnimation.RELATIVE_TO_SELF,.5f);
                rotateAnimation.setDuration(1000);

                rotateAnimation.setRepeatCount(Animation.INFINITE);
                rotateAnimation.setInterpolator(new LinearInterpolator());

                imageView.startAnimation(rotateAnimation);
            }
        });

        off.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                imageView.getAnimation().cancel();
                imageView.clearAnimation();
            }
        });

    }

}