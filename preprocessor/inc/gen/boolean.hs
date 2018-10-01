boomLine x = "#define BOOLEAN_BOOM_" ++ (show x) ++ "\t"
                ++ (show $ if x > 0 then 1 else 0)

main = do
  let ls = map boomLine $ [0 .. BOOM_LIMIT]
  mapM_ putStrLn ls
