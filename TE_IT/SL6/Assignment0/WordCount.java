package WCPackage;
import java.io.IOException;
import org.apache.hadoop.conf.*;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapreduce.*;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.util.*;

public class wc {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		Configuration c=new Configuration();
		String[] files = new GenericOptionsParser(c,args).getRemainingArgs();
		Path input = new Path(files[0]);
		Path output = new Path(files[1]);
		Job j = new Job(c,"wordcount");
		j.setJarByClass(wc.class);
		j.setMapperClass(Map.class);
		j.setReducerClass(Reduce.class);
		j.setOutputKeyClass(Text.class);
		j.setOutputValueClass(IntWritable.class);
		FileInputFormat.addInputPath(j,input);
		FileOutputFormat.setOutputPath(j,output);
		System.exit(j.waitForCompletion(true)?0:1);
	}
	
	public static class Map extends Mapper<LongWritable, Text , Text , IntWritable>{
		public void map(LongWritable Key, Text value, Context con) throws IOException, InterruptedException
		{
			String line = value.toString();
			String words[] = line.split(",");PracticeAssignments
			for(String word:words)
			{
				Text opKey = new Text (word.toLowerCase().trim());
				IntWritable opValue = new IntWritable (1);
				con.write(opKey, opValue);
			}
		}
	}
	public static class Reduce extends Reducer<Text, IntWritable, Text, IntWritable>
	{
		public void reduce(Text word, Iterable<IntWritable> values,Context con) throws IOException, InterruptedException
		{
			int sum=0;
			for(IntWritable value : values)
			{
				sum+=value.get();
			}
			con.write(word, new IntWritable(sum));
		}
	}
}
