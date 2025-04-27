#pragma library json

native json_parse(const json_str[], &out_id);
native json_free(ptr);

native json_get_int(ptr, key[], &output);
native json_get_float(ptr, key[], &Float:output);

//em teste
native json_get_bool(ptr, key[], &output);

native json_is_valid(const json_str[]);
native json_has_key(ptr, key[]);

native json_create(&output);
native json_set_string(ptr, key[], value[]);

native json_to_string(ptr, output[], size);
