function sumhexa (k)
  k = LOCMD5(k)
  return (string.gsub(k, ".", function (c)
           return string.format("%02x", string.byte(c))
         end))
end

function getKey(url)
    print("run...lua...")
    print(url)
    return sumhexa(url)
end