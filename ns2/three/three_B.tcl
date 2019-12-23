
set ns [new Simulator]

set tf [open 3.tr w]
$ns trace-all $tf

set nf [open out3.nam w]
$ns namtrace-all $nf

proc finish {} {
	global ns tf nf
	$ns flush-trace
	close $tf
	close $nf
	exec awk -f stats.awk 3.tr &
	exec nam out3.nam &
	exit 0
}

for {set i 0} {$i < 4} {incr i} {
	set n$i [$ns node]
}

$ns duplex-link $n0 $n2 2mb 20ms DropTail
$ns duplex-link $n1 $n2 2mb 20ms DropTail
$ns duplex-link $n2 $n3 200Kb 20ms DropTail
$ns queue-limit $n0 $n2 10

set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp
set tcpsink [new Agent/TCPSink]
$ns attach-agent $n3 $tcpsink
$ns connect $tcp $tcpsink

set ftp [new Application/FTP]
$ftp attach-agent $tcp

set udp [new Agent/UDP]
$ns attach-agent $n1 $udp
set null [new Agent/Null]
$ns attach-agent $n3 $null
$ns connect $udp $null

set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp

$ns at 0.5 "$ftp start"
$ns at 0.6 "$cbr start"
$ns at 7.0 "$cbr stop"
$ns at 7.5 "$ftp stop"
$ns at 8.0 "finish"

$ns run
