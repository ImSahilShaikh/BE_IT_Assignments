## Steps to run

- Download mpi.jar from : http://sourceforge.net/projects/mpjexpress/files/releases/ (Download latest version)
- Open terminal and use "export MPJ_HOME= << path of the mpj jar folder >> " <br> eg: export MPJ_HOME=/home/username/Downloads/MPI/mpj-v0_44
- Compile using: "javac -cp $MPJ_HOME/lib/mpj.jar filename.java"
- Execute using: "$MPJ_HOME/bin/mpjrun.sh -np <number of processes> Classname"
