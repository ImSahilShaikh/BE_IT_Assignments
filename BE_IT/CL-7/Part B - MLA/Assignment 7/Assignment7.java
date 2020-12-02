/*

Name : Sahil A. Shaikh
Roll No: 43365
Problem Statement: : On the given data perform the performance measurements using Simple Naïve Bayes algorithm such as Accuracy, Error rate, precision, Recall, TPR,FPR,TNR,FPR etc.

*/
import java.io.*;
import weka.classifiers.bayes.NaiveBayes;
import weka.classifiers.Evaluation;
import weka.core.Instances;
import weka.core.Debug;

class Assignment7
{
    public static void main(String[] args) throws Exception {
        
        BufferedReader dfReader = new BufferedReader(new FileReader("C:\\Program Files\\Weka-3-8-4\\data\\iris.arff"));
        Instances df = new Instances(dfReader);

        dfReader.close();

        int trainSize = (int) Math.round(df.numInstances() * 0.8);
        int testSize = df.numInstances() - trainSize;

        df.randomize(new Debug.Random(2));

        Instances train = new Instances(df,0,trainSize);
        Instances test = new Instances(df,trainSize,testSize);

        train.setClassIndex(train.numAttributes() - 1);
		test.setClassIndex(test.numAttributes() - 1);
		
		NaiveBayes nB = new NaiveBayes();
		nB.buildClassifier(train);
		System.out.println(nB);
		
		Evaluation eval = new Evaluation(test);
		eval.evaluateModel(nB, test);
		System.out.println(eval.toSummaryString("\nResults Testing\n", true));
		
		for(int i = 0; i < train.numClasses(); i++) {
			System.out.println("Class "+ i);
			System.out.println(eval.precision(i) + " " + eval.recall(i) + " " + eval.areaUnderROC(i));
		}
    }
}