/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: comment.c,v 1.1 2003/04/29 20:45:50 pinkfish Exp $
 * $Log: comment.c,v $
 * Revision 1.1  2003/04/29 20:45:50  pinkfish
 * Initial revision
 *
 * Revision 1.3  1998/04/16 12:52:49  pinkfish
 * Update to use the new report base inhertiable command.
 *
 * Revision 1.2  1998/02/28 02:47:28  presto
 * fixed destination directory for virtual object bugreps
 *
 * Revision 1.1  1998/01/06 05:29:43  ceres
 * Initial revision
 *
 */
/**
 * Does this nice bug reporting for the players.  Uses a neato
 * base object whizz bang thing now.
 * @author Pinkfish
 */

inherit "/cmds/report_base";

void create() {
   ::create();
   set_error_type("COMMENT");
   set_use_last_error(1);
} /* create() */
