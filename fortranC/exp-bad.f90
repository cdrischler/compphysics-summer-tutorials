      program expbad

!
!        program calculates exp(-x) as series
!        (bad programming style)


      implicit none

      integer :: max 
      parameter (max=20)

      double precision :: x(max)
      double precision :: down, min, step, sum, up, xx, start
      integer :: i, j, k
      integer :: kwrite

      data kwrite/6/

!       initialize
      min  = 1d-10

      start= 0.1d0
      step = 0.4d0

      x(1) = start

      do i = 2,max
      x(i)=x(i-1)+step
      end do

      open(kwrite, File = 'exp-bad.out', Status = 'Unknown')
      write (kwrite,10000)
10000 format (7x,'   x-value ',8x,' exp (-x)')

      do k = 1, max
      xx = x(k)

      sum = 1.d0
      i = 0
      down = 1.d0
      up = 1.d0

      do while ((abs((up/down)/sum)  >  min))   

      i = i + 1
      down = 1.d0 
      up = 1.d0
        do  j = 1, i
        up   = - up*xx
        down = down*j
        end do
      sum = sum + up/down
      end do

      write (kwrite,10001) xx, sum

      end do

10001 format(1x,2(d18.5))

      close(kwrite)
      Stop 'data saved in exp-bad.out'
      end program expbad
