//Selection sort with efficincy
import java.lang.*;
import java.util.*;


class P381_SelectionSort
{
    public static void main(String arr[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the size of array : ");
        int size = sobj.nextInt();

        Array aobj = new Array(size);
        aobj.Accept();
        aobj.Display();

        aobj.SelectionSort();
        System.out.println("Data after sorting:");
        aobj.Display();

    }
}
interface MarvellousSort
{
    public void Accept();
    public void Display();
    public void BubbleSort();
    public void InsertionSort();
    public void SelectionSort();
}

class Array implements MarvellousSort
{
    public int Arr[];

    public Array(int iSize)
    {
        Arr = new int[iSize];
    }

    public void Accept()
    {
        Scanner sobj = new Scanner(System.in);
        System.out.println("Enter elements");
        for(int i= 0;i <Arr.length; i++)
        {
            Arr[i] = sobj.nextInt();
        }
    }

    public void Display()
   {
        System.out.println("Elements of the array are");
        for(int i= 0;i <Arr.length; i++)
        {
           System.out.print(Arr[i]+"\t");
        }
        System.out.println();
   }
   public void BubbleSort(){}
   public void InsertionSort(){}
   
   public void SelectionSort()
   {
    int i=0,j=0,min_index=0,temp=0;
    for(i=0;i<Arr.length-1;i++)
    {
        min_index=i;
        for(j=i+1;j<Arr.length;j++)
        {
            if(Arr[min_index]>Arr[j])
            {
                min_index = j;
            }
        }
        if( i != min_index)
        {
            temp = Arr[i];
            Arr[i] = Arr[min_index];
            Arr[min_index] = temp;
        }
    }
   }
}

