/*
 * Copyright (c) 2018 IOTA Stiftung
 * https://github.com/iotaledger/iota.c
 *
 * Refer to the LICENSE file for licensing information
 */

#include <stdlib.h>

#include "cclient/request/get_inclusion_states.h"

get_inclusion_states_req_t* get_inclusion_states_req_new() {
  get_inclusion_states_req_t* req = (get_inclusion_states_req_t*)malloc(sizeof(get_inclusion_states_req_t));
  if (req) {
    req->transactions = NULL;
    req->tips = NULL;
  }
  return req;
}

void get_inclusion_states_req_free(get_inclusion_states_req_t** req) {
  if (!req || !(*req)) {
    return;
  }

  if ((*req)->transactions) {
    hash243_queue_free(&(*req)->transactions);
    (*req)->transactions = NULL;
  }
  if ((*req)->tips) {
    hash243_queue_free(&(*req)->tips);
    (*req)->tips = NULL;
  }
  free(*req);
  *req = NULL;
}
