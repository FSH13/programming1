bool leap_year(int years)
{
        //bereken of het huidig jaar een leap year is
        if (years%400 == 0)
        {
                return true;
        }
        else if (years%4 == 0 && years%100 != 0)
        {
                return true;
        }
        else{
        return false;
        }
}
