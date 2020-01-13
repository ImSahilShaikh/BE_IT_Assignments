package w;

import java.io.IOException;
import org.apache.hadoop.conf.*;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapreduce.*;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.util.*;


public class weather {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		Configuration c=new Configuration();
		String file[] = new GenericOptionsParser(c,args).getRemainingArgs();
		Path input= new Path(file[0]);
		Path output=new Path(file[1]);
		Job j=new Job(c,"mylog");
		j.setMapperClass(Map.class);
		j.setReducerClass(Reduce.class);
		j.setOutputKeyClass(Text.class);
		j.setOutputValueClass(IntWritable.class);
		FileInputFormat.addInputPath(j, input);
		FileOutputFormat.setOutputPath(j,output);
		System.exit(j.waitForCompletion(true)?0:1);
	}
	public static class Map extends Mapper<LongWritable,Text,Text,IntWritable>
	{
		public void map(LongWritable Key,Text value,Context con) throws IOException,InterruptedException
		{
			String line=value.toString();
			String userinfo[]=line.split("\n");
			Text userno=new Text();
			int login=0,logout=0;
			IntWritable time=new IntWritable();
			int i=0;
			for(String word:userinfo)
			{
				String user_details[]=word.split("\t");
				for(String user:user_details)
				{
					if(i%5==0)
						userno=new Text(word.toUpperCase().trim());
					else if(i%5==1)
						login=Integer.parseInt(user);
					else if(i%5==2)
						logout=Integer.parseInt(user);
					i++;
				}
				time=new IntWritable(logout-login);
				con.write(userno, time);
			}
		}
	}
	public static class Reduce extends Reducer<Text,IntWritable,Text,IntWritable>
	{
		private int max=0;
		private Text maxword=new Text();
		public void reduce(Text uid,Iterable<IntWritable> values, Context con) throws IOException,InterruptedException
		{
			int sum=0;
			for(IntWritable value: values)
			{
				sum+=value.get();
			}
			if(sum>max)
			{
				max=sum;
				maxword.set(uid);
			}
			//con.write(uid,new IntWritable(sum));
		}
		protected void cleanup(Context con) throws IOException,InterruptedException
		{
			con.write(maxword, new IntWritable(max));
		}
	}
}
