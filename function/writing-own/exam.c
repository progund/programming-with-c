int exam_grade (int points)
{
  if (points<0 || points>50)
    {
      return -1; 
    }
  else if (points > 37)
    {
      return 2;
    }
  else if (points > 24)
    {
      return 1;
    }
  return 0;
}

int course_grade (int exam, int handin)
{
  if ( (exam == 0) || (handin==0) )
    {
      return 0;
    }
  else if ( (exam==2) && (handin==1) )
    {
      return 2;
    }
  else if ( (exam==1) && (handin==1) )
    {
      return 1;
    }
  return -1;
}
