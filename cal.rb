require "numo/narray"
ary1 = Numo::DFloat[65, 80, 67, 35,58, 60, 72, 75, 68, 92,36, 50, 2, 58.5, 46, 42, 78, 62, 84, 70]
ary2 = Numo::DFloat[44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84]

print "理科-> 平均:", ary1.mean, " 標準偏差:", ary1.stddev, " 合計:", ary1.sum , "\n"
print "英語-> 平均:", ary2.mean, " 標準偏差:", ary2.stddev, " 合計:", ary2.sum, "\n"

for i in 0..20
   h1 = 10*(ary1[i]-ary1.mean) / ary1.stddev + 50;
   h2 = 10*(ary2[i]-ary2.mean) / ary2.stddev + 50;
   print i+1, "番の理科の偏差値:", h1, " 英語の偏差値:", h2, "\n"
end
ary1.sort!{|a,b| b<=>a}
ary2.sort!{|a,b| b<=>a} 
print "理科:"
p ary1
print "\n"
print "英語:"
p ary2
print "\n"
