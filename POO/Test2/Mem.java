import java.util.*;

abstract class Memorie{
    protected byte[] b;
    protected int size;
    public Memorie(int size) throws IllegalArgumentException{
	if(size<=0)
	    throw new IllegalArgumentException();
	this.size=size;
    }
    public byte[] read(int start, int end)throws IllegalArgumentException{
	if(start<0 || end<0 || start>end || start>=(size-1) || end>=(size-1))
	    throw new IllegalArgumentException();
	byte[] by = new byte[end-start+1];
	for(int i=start; i<=end; i++)
	    by[i]=b[i];
	return by;
    }
    protected int dim(){
	return size;
    }
}

class PROM extends Memorie{
    public PROM(final byte[] t, int size)throws IllegalArgumentException{
	super(size);
	b=t;
    }
}

class RandomROM extends Memorie{
    public RandomROM(int size)throws IllegalArgumentException{
	super(size);
	for(int i=0; i<size; i++){
	    if(Math.random()<0.5)
		b[i]=0;
	    else
		b[i]=1;
	}
    }
}

class RAM extends Memorie{
    public RAM(int size)throws IllegalArgumentException{
	super(size);
    }
    public void write(int start, byte[] by)throws IllegalArgumentException{
	if((start+by.length)>=size || start<0)
	    throw new IllegalArgumentException();
	for(int i=0; i<size; i++)
	    b[start+i] = by[i];
    }
}

class RedundantRAM extends RAM{
    private List<RAM> lista;
    public RedundantRAM(int size) throws IllegalArgumentException{
	super(size);
	lista = new ArrayList<RAM>();
    }
    public void addWritableMemory(RAM m) throws IllegalArgumentException{
	if(m.size<this.size)
	    throw new IllegalArgumentException();
	lista.add(m);
    }
    public void write(int start, byte[] by)throws IllegalArgumentException{
	super.write(start, by);
	for(RAM i:lista)
	    i.write(start, by);
    }
    public byte[] read(int start, int end)throws IllegalArgumentException{
	byte[] re = super.read(start, end);
	byte[] a;
	for(RAM i:lista){
	    a=i.read(start, end);
	    for(int j=0; j<a.length; j++)
		if(re[j]!=a[j])
		    throw new IllegalArgumentException();
	}
	return re;
    }
    public int dim(){
	int s=0;
	for(RAM i:lista)
	    s+=i.dim();
	return s;
    }
    public double grad(){
	return (double)dim()/size;
    }
}

