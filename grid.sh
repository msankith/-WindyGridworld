make
./simulator $1 $2
python plot.py temp.txt &
python plotPath.py policyRun.txt &
