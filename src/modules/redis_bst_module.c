#include "../redismodule.h"
#include "../bst.h"

Node* root = NULL;  

int BSTSearchCommand(RedisModuleCtx* ctx, RedisModuleString** argv, int argc) {
    if (argc != 2) return RedisModule_WrongArity(ctx);

    long long key;
    if (RedisModule_StringToLongLong(argv[1], &key) != REDISMODULE_OK) {
        return RedisModule_ReplyWithError(ctx, "ERR invalid key");
    }

    Node* result = searchNode(root, key);
    if (result != NULL) {
        RedisModule_ReplyWithLongLong(ctx, result->key);
    }
    else {
        RedisModule_ReplyWithNull(ctx);
    }

    return REDISMODULE_OK;
}

int BSTInsertCommand(RedisModuleCtx* ctx, RedisModuleString** argv, int argc) {
    if (argc != 2) return RedisModule_WrongArity(ctx);

    long long key;
    if (RedisModule_StringToLongLong(argv[1], &key) != REDISMODULE_OK) {
        return RedisModule_ReplyWithError(ctx, "ERR invalid key");
    }

    root = insertNode(root, key);
    RedisModule_ReplyWithSimpleString(ctx, "OK");

    return REDISMODULE_OK;
}

int BSGetCommand(RedisModuleCtx* ctx, RedisModuleString** argv, int argc) {
    if (argc != 2) return RedisModule_WrongArity(ctx);

    long long key;
    if (RedisModule_StringToLongLong(argv[1], &key) != REDISMODULE_OK) {
        return RedisModule_ReplyWithError(ctx, "ERR invalid key");
    }

    Node* result = searchNode(root, key);
    if (result != NULL) {
        RedisModule_ReplyWithLongLong(ctx, result->key);
    }
    else {
        RedisModule_ReplyWithNull(ctx);
    }

    return REDISMODULE_OK;
}

int BSSetCommand(RedisModuleCtx* ctx, RedisModuleString** argv, int argc) {
    if (argc != 2) return RedisModule_WrongArity(ctx);

    long long key;
    if (RedisModule_StringToLongLong(argv[1], &key) != REDISMODULE_OK) {
        return RedisModule_ReplyWithError(ctx, "ERR invalid key");
    }

    root = insertNode(root, key);
    RedisModule_ReplyWithSimpleString(ctx, "OK");

    return REDISMODULE_OK;
}

int RedisModule_OnLoad(RedisModuleCtx* ctx) {
    if (RedisModule_Init(ctx, "bst", 1, REDISMODULE_APIVER_1) == REDISMODULE_ERR) return REDISMODULE_ERR;

    if (RedisModule_CreateCommand(ctx, "bsget", BSTSearchCommand, "readonly", 1, 1, 1) == REDISMODULE_ERR) return REDISMODULE_ERR;
    if (RedisModule_CreateCommand(ctx, "bsset", BSTInsertCommand, "write", 1, 1, 1) == REDISMODULE_ERR) return REDISMODULE_ERR;

    return REDISMODULE_OK;
}