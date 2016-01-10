#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
int main()
{
	int i,j,k,l,r,c,f=0,z,cnt,d;
	char a[20][20],t;
	cout<<"Enter the no. of rows and columns you want in the game: ";
	cin>>r>>c;
	for(i=0;i<r;i++)
	for(j=0;j<c;j++)
	a[i][j]='n';
	while(1)
	{
		r:
		d=1;
		f++;
		for(i=0;i<r;i++)
	    for(j=0;j<c;j++)
	    {
	    	if(a[i][j]=='n')
	    	{
	    		d=0;
	    		goto y;
	    	}
	    }
	    y:
	    if(d==1)
	    goto w;
		if(f%2!=0)
		{
			cout<<"Player 1, enter your column no. ";
			cin>>z;
		    for(i=0;i<r;i++)
		    {
		    	if(a[0][z-1]!='n')
		    	{
		    		cout<<"Wrong Option\n";
		    		f--;
					goto r;
			    }
				if(a[i+1][z-1]!='n')
		    	{
		    	a[i][z-1]='X';
		    	break;
		        }
				if(i+1==r)
		    	{
		    	a[i][z-1]='X';
		         break;
		        }
		    }
	    }
		else
	    {
			cout<<"Player 2, enter your column no. ";
			cin>>z;
		    for(i=0;i<r;i++)
		    {
		    	if(a[0][z-1]!='n')
		    	{
		    		cout<<"Wrong Option\n";
		    		f--;
					goto r;
			    }
				if(a[i+1][z-1]!='n')
		    	{
		    	a[i][z-1]='O';
		    	break;
		        }
				if(i+1==r)
		    	{
		    	a[i][z-1]='O';
		         break;
		        }
			}
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(a[i][j]=='n')
				cout<<"_ ";
				else
				cout<<a[i][j]<<" ";
			}
		    cout<<endl;
		}
		for(i=0;i<r;i++)
		{
			cnt=0;
			for(j=0;j<c;j++)
			{
				if(a[i][j]!='n'&&a[i][j]==a[i][j-1])
				cnt++;
				else
				cnt=0;
				if(cnt==3)
				goto w;
			}
		}
		for(j=0;j<c;j++)
		{
			cnt=0;
			for(i=0;i<r;i++)
			{
				if(a[i][j]!='n'&&a[i][j]==a[i-1][j])
				cnt++;
				else
				cnt=0;
				if(cnt==3)
				goto w;
			}
		}
		for(i=r-1,j=0;i>=0;i--)
	    {
	    	t='n';
	    	cnt=0;
			for(k=i,l=j;k<r;k++,l++)
			{
				if(a[k][l]!='n'&&a[k][l]==t)
				cnt++;
				else
				cnt=0;
				if(cnt==3)
				goto w;
				t=a[k][l];
			}
	    }
		for(i=0,j=0;i<r;i++)
		{
			t='n';
	    	cnt=0;
			for(k=i,l=j;k>=0;k--,l++)
			{
				if(a[k][l]!='n'&&a[k][l]==t)
				cnt++;
				else
				cnt=0;
				if(cnt==3)
				goto w;
				t=a[k][l];
			}
		}
		for(i=r-1,j=c-1;i>=0;i--)
		{
			t='n';
	    	cnt=0;
			for(k=i,l=j;k<r;k++,l--)
			{
				if(a[k][l]!='n'&&a[k][l]==t)
				cnt++;
				else
				cnt=0;
				if(cnt==3)
				goto w;
				t=a[k][l];
			}
		}
		for(i=0,j=c-1;i<r;i++)
		{
			t='n';
	    	cnt=0;
			for(k=i,l=j;k>=0;k--,l--)
			{
				if(a[k][l]!='n'&&a[k][l]==t)
				cnt++;
				else
				cnt=0;
				if(cnt==3)
				goto w;
				t=a[k][l];
			}
		}
	}
	w:
    if(d==1)
    cout<<"Match Draw";
    else
    {
    	if(f%2!=0)
    	cout<<"Player 1 wins";
    	else
    	cout<<"Player 2 wins";
    }
}
