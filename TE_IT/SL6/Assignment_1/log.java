package log;

import java.io.IOException;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class log {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		
		Configuration c=new Configuration();
		
		Path input = new Path(args[0]);
		Path output = new Path(args[1]);
		
		Job j = new Job(c,"logfile");//second parameter is name of job
		
		j.setJarByClass(log.class);
		j.setMapperClass(Map.class);
		j.setReducerClass(Reduce.class);
		j.setOutputKeyClass(Text.class);
		j.setOutputValueClass(IntWritable.class);
		FileInputFormat.addInputPath(j, input);
		FileOutputFormat.setOutputPath(j, output);
		System.exit(j.waitForCompletion(true)?0:1);
		

	}
	
	public static class Map extends Mapper <LongWritable, Text, Text, IntWritable>
	{
		public void map(LongWritable key, Text value, Context con) throws InterruptedException, IOException
		{
			String line = value.toString();
			String words[] = line.split(",");
			
			Text output = new Text(words[0].toUpperCase().trim());
			
			int min = Integer.parseInt(words[1]);
			int max = Integer.parseInt(words[2]);
			
			int time = max-min;
			
			IntWritable op = new IntWritable(time);
			
			con.write(output, op);
		}
	}
	
	public static class Reduce extends Reducer <Text, IntWritable, Text, IntWritable >
	{
		public void reduce(Text val, Iterable<IntWritable> value, Context con) throws InterruptedException, IOException
		{
			int sum=0;
			
			for(IntWritable values: value)
			{
				sum+=values.get();
			}
			con.write(val, new IntWritable(sum));
		}
	}

}