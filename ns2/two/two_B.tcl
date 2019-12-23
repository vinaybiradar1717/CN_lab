set ns [new Simulator]

set tf [open 2.tr w]
$ns trace-all $tf

set nf [open out2.nam w]
$ns namtrace-all $nf

proc finish {} {
	global ns tf nf
	$ns flush-trace
	close $tf
	close $nf
	exec awk -f stats.awk 2.tr &
	exec nam out2.nam &
	exit 0
}

for {set i 0} {$i < 4} {incr i} {
	set n$i [$ns node]
}

$ns duplex-link $n0 $n2 2mb 20ms DropTail
$ns duplex-link $n1 $n2 2mb 20ms DropTail
$ns duplex-link $n2 $n3 2mb 20ms DropTail
$ns queue-limit $n0 $n2 10


set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0
set sink0 [new Agent/TCPSink]
$ns attach-agent $n3 $sink0
$ns connect $tcp0 $sink0

set telnet [new Application/Telnet]
$telnet attach-agent $tcp0

set tcp1 [new Agent/TCP]
$ns attach-agent $n1 $tcp1
set sink1 [new Agent/TCPSink]
$ns attach-agent $n3 $sink1
$ns connect $tcp1 $sink1

set ftp [new Application/FTP]
$ftp attach-agent $tcp1

$ns at 0.5 "$telnet start"
$ns at 0.6 "$ftp start"
$ns at 8.0 "$ftp stop"
$ns at 8.5 "$telnet stop"
$ns at 9.0 "finish"

$ns run
