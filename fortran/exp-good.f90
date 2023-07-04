      program expgood
!
!        program calculates exp(-x) as series
!        (good programming style)

      implicit none

      integer :: max
      parameter (max=20)

      double precision :: x(max) 
      double precision :: element, min, step, sum, xx, start
      integer :: n, i
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

      open  (kwrite, File = 'exp-good.out', Status = 'Unknown')
      write (kwrite,10000)
10000 format (7x,'   x-value ',8x,' exp (-x)') 

!          prepare summation

      do i = 1,max
      xx = x(i)                                             
      sum     = 1.d0
      element = 1.d0
      n = 0

!          summation

      do while ((abs(element/sum) > min))

      n = n + 1
      element = element*(-xx)/float(n)
      sum = sum + element
      end do

      write (kwrite,10001) xx, sum
      end do

      close(kwrite)

10001 format (1x,2(d18.5))

      stop 'data saved in exp-good.out'

      end program expgood
