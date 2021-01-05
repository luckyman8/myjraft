Options options;

SstFileWriter sst_file_writer(EnvOptions(), options);
// Path to where we will write the SST file
std::string file_path = "/home/usr/file1.sst";

// Open the file for writing
Status s = sst_file_writer.Open(file_path);
if (!s.ok()) {
    printf("Error while opening file %s, Error: %s\n", file_path.c_str(),
           s.ToString().c_str());
    return 1;
}

// Insert rows into the SST file, note that inserted keys must be 
// strictly increasing (based on options.comparator)
for (...) {
  s = sst_file_writer.Put(key, value);
  if (!s.ok()) {
    printf("Error while adding Key: %s, Error: %s\n", key.c_str(),
           s.ToString().c_str());
    return 1;
  }
}

// Close the file
s = sst_file_writer.Finish();
if (!s.ok()) {
    printf("Error while finishing file %s, Error: %s\n", file_path.c_str(),
           s.ToString().c_str());
    return 1;
}
return 0;
