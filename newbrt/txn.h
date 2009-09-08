#ifndef TOKUTXN_H
#define TOKUTXN_H

#ident "$Id: txn.h 12375 2009-05-28 14:14:47Z yfogel $"
#ident "Copyright (c) 2007, 2008, 2009 Tokutek Inc.  All rights reserved."
#ident "The technology is licensed by the Massachusetts Institute of Technology, Rutgers State University of New Jersey, and the Research Foundation of State University of New York at Stony Brook under United States of America Serial No. 11/760379 and to the patents and/or patent applications resulting from it."

int toku_txn_begin_txn (TOKUTXN parent_tokutxn, TOKUTXN *tokutxn, TOKULOGGER logger);
int toku_txn_begin_with_xid (TOKUTXN parent_tokutxn, TOKUTXN *tokutxn, TOKULOGGER logger, TXNID xid);

int toku_txn_commit_txn (TOKUTXN txn, int nosync, YIELDF yield, void *yieldv);
int toku_txn_commit_with_lsn(TOKUTXN txn, int nosync, YIELDF yield, void *yieldv, LSN oplsn);

int toku_txn_abort_txn(TOKUTXN txn, YIELDF yield, void *yieldv);
int toku_txn_abort_with_lsn(TOKUTXN txn, YIELDF yield, void *yieldv, LSN oplsn);

void toku_txn_close_txn(TOKUTXN txn);
XIDS toku_txn_get_xids (TOKUTXN);

// Returns TRUE if a is older than b
BOOL toku_txnid_older(TXNID a, TXNID b);

// Returns TRUE if a == b
BOOL toku_txnid_eq(TXNID a, TXNID b);

// Returns TRUE if a is newer than b
BOOL toku_txnid_newer(TXNID a, TXNID b);

#endif //TOKUTXN_H
