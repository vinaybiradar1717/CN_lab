BEGIN{    
    tr=0;
	td=0;
	
}
{
	ev = $1;
	if(ev == "r"){tr++;}
	if(ev == "d"){td++;}
    
}
END{
    printf("Total Received: %d\n",tr);
    printf("Total Dropped: %d\n",td);
}
