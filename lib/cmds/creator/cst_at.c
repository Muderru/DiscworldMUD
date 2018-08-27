/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: cst_at.c,v 1.1 1998/01/06 05:25:41 ceres Exp $
 * $Log: cst_at.c,v $
 * Revision 1.1  1998/01/06 05:25:41  ceres
 * Initial revision
 * 
*/
/* stats command, trial out by Turrican for a commands daemon. -*- LPC -*- */

#include <creator.h>

mixed cmd(string str) {
  object *ob, thing;
  mixed *ob1, *thing1;
  string s, bing;
  string long_fields, temp;   /* added by ember to produce long and short fields */
  int long_length;  /* fields are divided into long and short fields by this */

  bing = "";
  str = (string)this_player()->expand_nickname(str);
  ob = WIZ_PRESENT->wiz_present(str, this_player());
  if (!sizeof(ob)) {
    write("No such object.\n");
    return 1;
  }
  foreach (thing in ob) {
    ob1 = (mixed *)thing->stats();
    if (!pointerp(ob1))
      continue;
    s = "";
    long_fields = "";
    long_length = ( (int)this_player()->query_cols() / 3 ) - 1;
    foreach (thing1 in (pointerp(ob1[0][0])?ob1[0]:ob1))
      if ( thing1[ 1 ] && !sscanf(thing1[0],"(%s)",temp)) {
        temp = thing1[0] +": "+ thing1[ 1 ] +"\n";
/* this test will incorrectly assess some fields which have line feeds in
 * them as 'long fields', but who really cares? */
        if (strlen(temp) > long_length) long_fields += temp;
        else s += temp;
      }
    bing += sprintf("%-*#s\n", this_player()->query_cols(), long_fields) +
        sprintf( "%-*#s\n", this_player()->query_cols(), s );
  }
  this_player()->more_string(bing);
  return 1;
}

void dest_me() {
  destruct(this_object());
}

void clean_up() {
  dest_me();
}

void reset() {
  dest_me();
}
