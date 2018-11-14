require "numo/narray"

ary1 = Numo::DFloat[65,80,67,35,58,60,72,75,68,92,36,50,2,58.5,46,42,78,62,84,70]
ary2 = Numo::DFloat[44,87,100,63,52,60,58,73,55,86,29,56,89,23,65,84,64,27,86,84]

print("理科の平均:", ary1.mean, "\n" "標準偏差:", ary1.stddev,"\n" "合計点:", ary1.sum,"\n")
print("英語の平均:", ary2.mean, "\n" "標準偏差:", ary2.stddev,"\n" "合計点:", ary2.sum,"\n")

print("\n理科の偏差値")
for i in 0..19
	d1 = 50+(ary1[i]-ary1.mean)/2
	print(d1)
end
print("\n英語の偏差値")
for i in 0..19
	d2 = 50+(ary2[i]-ary2.mean)/2	
	print(d2)
end

print("理科(高い順):",ary1.sort.to_a)
print("英語(高い順):",ary2.sort.to_a)
