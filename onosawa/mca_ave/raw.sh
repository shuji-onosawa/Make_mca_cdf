#/bin/csh -f

foreach YEAR(2015)
   foreach MONTH(4)
     foreach DAY( 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31)
       echo $YEAR $MONTH $DAY
        bnd $YEAR $MONTH $DAY 8
    end
  end
end
