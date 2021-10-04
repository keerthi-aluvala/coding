/* Majority Element */

int majorityElement(int a[], int size)
    {
        int index=0, count=1;
        for(int i=1; i<size; i++)
        {
            if(a[index]==a[i])
                count++;
            else
                count--;
            if(count==0)
            {
                index=i;
                count=1;
            }
        }
        count = 0;
        for(int i=0; i<size; i++)
        {
            if(a[i]==a[index])
                count++;
            if(count>size/2)
                return a[index];
        }
        return -1;
    }
    
 /* Bit Manipulation */  
int majorityElement(int a[], int size)
    {
        int number=0;
        int n = sizeof(int)*8;
        for(int i=0; i<n; i++)
        {
            int count=0;
            for(int j=0; j<size; j++)
            {
                if(a[j]&(1<<i))
                    count++;
            }
            if(count>size/2)
                number += (1<<i);
        }
        int count=0;
        for(int i=0; i<size; i++)
        {
            if(a[i]==number)
                count++;
        }
        if(count>size/2)
            return number;
        return -1;
    }
